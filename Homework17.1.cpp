// Homework17.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "sql_query_builder.h"

int main(){
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    //query_builder.SomeMethod("<");

    std::cout << query_builder.BuildQuery() << std::endl;
    //static_assert(query_builder.BuildQuery(),
    //    "SELECT name, phone FROM students WHERE id=42 AND name=John;");
}