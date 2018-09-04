#include <iostream>
#include <vector>
#include <fstream>

void zero_matrix(std::vector<std::vector<int>> &matrix)
{
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();
    std::vector<bool> rows(num_rows, false);
    std::vector<bool> cols(num_cols, false);

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                if (!rows[i])
                {
                    rows[i] = true;
                }
                if (!cols[j])
                {
                    cols[j] = true;
                }
            }
        }
    }

    std::cout << "made it this far\n";
    for (int i = 0; i < num_rows; ++i)
    {
        if (rows[i])
        {
            for (int j = 0; j < num_cols; ++j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < num_cols; ++i)
    {
        if (cols[i])
        {
            for (int j = 0; j < num_rows; ++j)
            {
                matrix[j][i] = 0;
            }
        }
    }

    return;
}

void print_matrix(std::vector<std::vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void read_matrix(std::vector<std::vector<int>> &matrix, std::string filename)
{
    int m, n, x;
    std::ifstream infile;
    infile.open(filename);
    infile >> m >> n;
    std::vector<int> row;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            infile >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
        row.clear();
    }
    infile.close();
}

int main(int argc, char **argv)
{
    std::vector<std::vector<int>> matr;
    for (int i = 1; i < argc; ++i)
    {
        read_matrix(matr, argv[i]);
        std::cout << "Original matrix:\n";
        print_matrix(matr);
        std::cout << "Zero matrix:\n";
        zero_matrix(matr);
        print_matrix(matr);
        std::cout << "\n";
        matr.clear();
    }

    return 0;
}