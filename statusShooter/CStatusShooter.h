#ifndef CSTATUS_H
#define CSTATUS_H
#include <iostream>
#include <pqxx/pqxx>
#include <glog/logging.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <errno.h>
#include <algorithm>
#include <sstream>
#include <yaml-cpp/yaml.h>
#include "../include/CFile.h"
/*dbname=netrunner user=postgres password=sam1 hostaddr=127.0.0.1 port=5432*/
class CStatusShooter
{
public:
	CStatusShooter();
	~CStatusShooter();
	int addToSql(std::string cpu, std::string ram, std::string temperature, std::string swap);
	void checkSize();
private:
	void readConfig();
	const std::string configFilePath = "/etc/statusShooter/config.yml";
	YAML::Node configFile;
	std::string userName;
	std::string password;
	std::string dbName;
	std::string tableName;
	const std::string host = "127.0.0.1";
	const std::string port = "5432";
	std::string connectionString;
	std::string query;
		/* data */
};
#endif