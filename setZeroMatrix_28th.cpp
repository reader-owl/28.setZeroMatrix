#include <iostream>

/*
                    Q. Set matrix zeroes

                explanation - we will given a n*m matrix, this matrix only has zeroes and ones and we have 
                                to find zeroes
                                we have mark(with 0) the whole row and column in which zero exists
                                (refer the video for explanation)

            Brute sol -  we will iterate through whole matrix to find '0'. after finding zero we will mark 
                            the elements of the row and the column as '-1' (except for any zero)
                            marking the whole row and column as '0' will create problem
                            after completing marking, at the end we will convert every '-1' into '0'

        pseudo code
for(i=0; i<n; i++)                  // O(n*m)
{
    for(j=0; j< m; j++)
    {
        if(arr[i][j] == 0)
        {
            markRow(i)
            markCol(j)
        }
    }
}

markRow(i)                          // O(m)
{
    for(j=0; j<m; j++)
    {
        if(arr[i][j] != 0)          // marking nonzero
            arr[i][j] = -1;
    }
}

markCol(j)                          // O(n)
{
    for(i=0; i<n; i++)
    {
        if(arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

// converting -1 to 0
for(i=0->n)                         // O(n*m)
{
    for(j=0->m)
    {
        if(arr[i][j] == -1)
            arr[i][j] = 0;
    }
}

            TC - O((n*m) * (n+m) * (n*m))
               - O(N^3)                     // nearly


                Better sol -  we will iterate through whole matrix to find '0'. after finding zero we will mark 
                            the row and the columnas '1'. we do this for every zero and at the last we will
                            convert all the elements to '0' of the marked row and column

        pseudo code
col[m] = {0}, row[n] = {0}
for(i=0->n)
{
    for(j=0->m)
    {
        if(arr[i][j] == 0)
        {
            row[i] = 1;
            col[j] = 1;
        }
    }
}

// coverting elements to 0 of the rows and columns
for(i=0->n)
{
    for(j=0->m)
    {
        if(row[i] || col[j])        // if(row or column is marked)
            a[i][j] = 0
    }
}


        Actual code
vecto<vector<int>> zeroMatrix(vector<int> &matrix, int n, int m)
{
    int row[n] = {0};
    int col[m] = {0};
    for(int i = 0; i < n; i++)              // O(n*m)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // converting marked row and column elements to 0
    for(int i = 0; i < n; i++)              // O(n*m)
    {
        for(int j = 0; j < m; j++)
        {
            if(row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

                TC - O(2 * n*m)
                SC - O(n) + O(m)



                Optimal sol -  refer video for explanation

        Actual code
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // int row[n] = {0};  -> matrix[something][0]
    // int col[m] = {0};  -> matrix[0][something]

    int col0 = 1;
    for(int i = 0; i < n; i++)                  // O(n*m)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                // mark the i-th row
                matrix[i][0] = 0;
                // mark the j-th col
                if(j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i = 0; i < n; i++)                  // O(2 * n*m)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] != 0)
            {
                // check for col & row
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0)
    {
        for(int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    if(col0 == 0)
    {
        for(int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
    
    return matrix;
}

                TC - O(3 * n*m)
                SC - O(1)
*/

int main()
{
    std::cout << "Hello World!\n";
}