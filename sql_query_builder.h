#pragma once
#include <iostream>
#include <vector>
#include <map>


struct SelectQuery {
	std::string queryname;
	std::vector<std::string> addcolumns;
	std::string addfrom;
	std::string somemethod = "=";
	std::map<std::string, std::string> addwhere;
};

class SqlSelectQueryBuilder {
private:
	SelectQuery selectquery;

public:
	SqlSelectQueryBuilder& AddColumn(std::string addingColumn) {
		selectquery.addcolumns.push_back(addingColumn);
		return *this;
	}
	SqlSelectQueryBuilder& AddFrom(std::string addingFrom) {
		selectquery.addfrom = addingFrom;
		return *this;
	}
	SqlSelectQueryBuilder& AddWhere(std::string addingWherename, std::string addingWhere) {
		selectquery.addwhere[addingWherename] = addingWhere;
		return *this;
	}
	std::string BuildQuery() {
		std::string resQuery = "SELECT ";
		if (selectquery.addcolumns.empty()) {
			resQuery = resQuery + "* FROM";
		}
		else {
			for (int i = 0; i < selectquery.addcolumns.size(); i++) {
				if (i != (selectquery.addcolumns.size() - 1)) {
					resQuery = resQuery + selectquery.addcolumns[i] + ", ";
				}
				else {
					resQuery = resQuery + selectquery.addcolumns[i] + " FROM ";
				}
			}
		}
		resQuery = resQuery + selectquery.addfrom + " WHERE ";
		int i = 0;
		for (auto it = selectquery.addwhere.begin(); it != selectquery.addwhere.end(); it++) {
			if (i != 0) {
				resQuery = resQuery + " AND " + (it->first + selectquery.somemethod + it->second);
			}
			else if (i == 0) {
				resQuery = resQuery + (it->first + selectquery.somemethod + it->second);
			}
			i++;
		}
		resQuery = resQuery + ";";
		return resQuery;
	}
	SqlSelectQueryBuilder& SomeMethod(std::string action) {
		selectquery.somemethod = action;
		return *this;
	}
};