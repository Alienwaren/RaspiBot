#include "CStatusShooter.h"
CStatusShooter::CStatusShooter()
	: userName(""), password(""), connectionString(""), query("")
{
	configFile = YAML::LoadFile(configFilePath);
	readConfig();
}
void CStatusShooter::readConfig()
{
	YAML::Node sqlConfig = configFile["sql"];
	userName = sqlConfig["username"].as<std::string>();
	password = sqlConfig["password"].as<std::string>();
	dbName = sqlConfig["dbname"].as<std::string>();
	tableName = sqlConfig["tablename"].as<std::string>();
	connectionString = "dbname="+dbName+" user="+userName+" password="+password+" hostaddr="+host+" port="+port;
	// query = "INSERT INTO "+tableName+" VALUES(";
}
int CStatusShooter::addToSql(std::string cpu, std::string ram, std::string temperature, std::string swap)
{
	pqxx::connection dbConn(connectionString);
	query = "INSERT INTO "+tableName+"(\"cpuFreq\",\"ramFree\",\"temperatureValue\",\"swapUsed\") VALUES(" + cpu + "," + ram + "," + temperature + "," + swap + ");";
	pqxx::work sender(dbConn);
	sender.exec(query);
	sender.commit();
	// std::cout << query << std::endl;
	return 0;
}
CStatusShooter::~CStatusShooter()
{

}