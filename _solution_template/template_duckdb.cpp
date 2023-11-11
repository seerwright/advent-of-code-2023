#include <iostream>
#include <duckdb.hpp>
using namespace duckdb;

int main() {
    try {
        // Establish a connection to DuckDB

        DuckDB db(nullptr);
        Connection con(db);
        duckdb::unique_ptr<QueryResult> result;

        // con.Query("SELECT NOW()")->Print();

        con.Query("CREATE TABLE integers(i INTEGER, j INTEGER)");
        con.Query("INSERT INTO integers VALUES (3, 4), (5, 6), (7, NULL)");
        
        result = con.Query("SELECT * FROM integers");

        idx_t row_count = 0;
        for (auto &row : *result) {
            //string i = row.GetValue<int>(0) ? (typeid(row.GetValue<int>(0)) == typeid(string)) : "NULL";
            
            bool is_null = typeid(row.GetValue<int>(0)) == typeid(string);

            std::cout<< row.GetValue<int>(0) << ", " << row.GetValue<int>(1) << std::endl;
            row_count++;
        }


    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
