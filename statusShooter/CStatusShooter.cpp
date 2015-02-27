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
	query = "INSERT INTO "+tableName+" VALUES(";
}
int CStatusShooter::addToSql(std::string cpu, std::string ram, std::string temperature, std::string swap)
{
	pqxx::connection dbConn(connectionString);
	query += cpu + "," + ram + "," + temperature + "," + swap;
	std::cout << query;
	// pqxx::work actualQueries(query);
	// actualQueries.commit();
	return 0;
}
CStatusShooter::~CStatusShooter()
{

}