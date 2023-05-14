#include <iostream>
#include<cstdlib>
#include <algorithm>
using namespace std;
int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * fact(n - 1);
}
int main()
{
    int n=7;
    int skills1[n][5]={{1,0,3,0,1},{2,3,0,1,1},{1,0,0,1,1},{0,1,2,1,1},{2,0,0,1,0},{1,2,0,3,1},{1,2,2,0,1}};
    string roll[n];
    int m=2;
    string ProjectName[m];
    int Projects[m][5]={{1,1,2,0,0},{0,0,2,3,1}};

    int skills[5 * m][5] = {0,0,0,0,0};
    int parNos1[5 * m] = {0};
    int completions[fact(5 * m)] = {0};
    int completions1[fact(n)] = {0};
    if (n < (5 * m))
    {
        for (int i = 0; i < 5 * m; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                skills[i][j] = skills1[i][j];
            }
        }
        for (int i = 0; i < 5 * m; i++)
        {
            parNos1[i] = i;
        }
        int **permutations = new int *[fact(5*m)];
        for (int i = 0; i < fact(5*m); ++i)
        {
            permutations[i] = new int[5 * m];
        }
        int *numbers = new int[5 * m];
        for (int i = 0; i < 5 * m; ++i)
        {
            numbers[i] = i;
        }

        int row = 0;
        do
        {
            for (int i = 0; i < 5 * m; ++i)
            {
                permutations[row][i] = numbers[i];
            }
            ++row;
        } while (next_permutation(numbers, numbers + 5 * m));
        for (int i = 0; i < fact(5*m); i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < 5 * m; k = k + 5)
                {
                    if (Projects[j][0] - skills[permutations[i][k]][0] >= 2 || Projects[j][1] - skills[permutations[i][k + 1]][1] >= 2 || Projects[j][2] - skills[permutations[i][k + 2]][2] >= 2 || Projects[j][3] - skills[permutations[i][k + 3]][3] >= 2 || Projects[j][4] - skills[permutations[i][k + 4]][4] >= 2)
                        continue;
                    else
                    {
                        if (skills[permutations[i][k]][0] >= Projects[j][0] && skills[permutations[i][k + 1]][1] >= Projects[j][1] && skills[permutations[i][k + 2]][2] >= Projects[j][2] && skills[permutations[i][k + 3]][3] >= Projects[j][3] && skills[permutations[i][k + 4]][4] >= Projects[j][4])
                        {
                        completions[i]++;
                        }
                        else 
                        {
                            // Create a dynamically allocated 2D array
                            int **arr = new int *[fact(5)];
                            for (int i = 0; i < fact(5); ++i)
                            {
                                arr[i] = new int[5];
                            }
                            // Generate permutations
                            int *numbers = new int[5];
                            for (int i = 0; i < 5; ++i)
                            {
                                numbers[i] = i;
                            }

                            int row = 0;
                            do
                            {
                                for (int i = 0; i < 5; ++i)
                                {
                                    arr[row][i] = numbers[i];
                                }
                                ++row;
                            } while (next_permutation(numbers, numbers + 5));

                            for (int a = 0;a<120;a++)
                            {
    
                                if(skills[arr[a][0]][0]-skills[arr[a][1]][0]<=1&&skills[arr[a][1]][1]-skills[arr[a][2]][1]<=1&&skills[arr[a][2]][2]-skills[arr[a][3]][2]<=1&&skills[arr[a][3]][3]-skills[arr[a][4]][3]<=1&&skills[arr[a][4]][4]-skills[arr[a][0]][4]<=1&&skills[arr[a][0]][0]-skills[arr[a][1]][0]>=0&&skills[arr[a][1]][1]-skills[arr[a][2]][1]>=0&&skills[arr[a][2]][2]-skills[arr[a][3]][2]>=0&&skills[arr[a][3]][3]-skills[arr[a][4]][3]>=0&&skills[arr[a][4]][4]-skills[arr[a][0]][4]>=0)
                                {
                                completions[i]++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        // Create a dynamically allocated 2D array
        int **permutations = new int *[fact(n)];
        for (int i = 0; i < fact(n); ++i)
        {
            permutations[i] = new int[n];
        }

        // Generate permutations
        int *numbers = new int[n];
        for (int i = 0; i < n; ++i)
        {
            numbers[i] = i;
        }

        int row = 0;
        do
        {
            for (int i = 0; i < n; ++i)
            {
                permutations[row][i] = numbers[i];
            }
            ++row;
        } while (next_permutation(numbers, numbers + n));
        for (int i = 0; i < fact(n); i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < 5 * m; k = k + 5)
                {
                    if (Projects[j][0] - skills1[permutations[i][k]][0] >= 2 || Projects[j][1] - skills1[permutations[i][k + 1]][1] >= 2 || Projects[j][2] - skills1[permutations[i][k + 2]][2] >= 2 || Projects[j][3] - skills1[permutations[i][k + 3]][3] >= 2 || Projects[j][4] - skills1[permutations[i][k + 4]][4] >= 2)
                    continue;
                    else
                    {
                        if (skills1[permutations[i][k]][0] >= Projects[j][0] && skills1[permutations[i][k + 1]][1] >= Projects[j][1] && skills1[permutations[i][k + 2]][2] >= Projects[j][2] && skills1[permutations[i][k + 3]][3] >= Projects[j][3] && skills1[permutations[i][k + 4]][4] >= Projects[j][4])
                        completions1[i]++;
                        else 
                        {

                            // Create a dynamically allocated 2D array
                            int **arr = new int *[fact(n)];
                            for (int i = 0; i < fact(n); ++i)
                            {
                                arr[i] = new int[5];
                            }

                            // Generate permutations
                            int *numbers = new int[5];
                            for (int i = 0; i < 5; ++i)
                            {
                                numbers[i] = i;
                            }

                            int row = 0;
                            do
                            {
                                for (int i = 0; i < 5; ++i)
                                {
                                    arr[row][i] = numbers[i];
                                }
                                ++row;
                            } while (next_permutation(numbers, numbers + 5));

                            for (int a = 0;a<120;a++)
                            {
                                if(skills1[arr[a][0]][0]-skills1[arr[a][1]][0]<=1&&skills1[arr[a][1]][1]-skills1[arr[a][2]][1]<=1&&skills1[arr[a][2]][2]-skills1[arr[a][3]][2]<=1&&skills1[arr[a][3]][3]-skills1[arr[a][4]][3]<=1&&skills1[arr[a][4]][4]-skills1[arr[a][0]][4]<=1&&skills1[arr[a][0]][0]-skills1[arr[a][1]][0]>=0&&skills1[arr[a][1]][1]-skills1[arr[a][2]][1]>=0&&skills1[arr[a][2]][2]-skills1[arr[a][3]][2]>=0&&skills1[arr[a][3]][3]-skills1[arr[a][4]][3]>=0&&skills1[arr[a][4]][4]-skills1[arr[a][0]][4]>=0)
                                completions1[i]++;
                            }
                        }
                    }
                }
            }
        }
    
    }
    int completions2[fact(5*m)+fact(n)];
    for(int i=0;i<fact(5*m)+fact(n);i++)
    {
        if(i<fact(5*m))
        completions2[i]=completions[i];
        else
        completions2[i]=completions1[i-fact(5*m)];
    }
    int max_projects=0;
    for(int i=0;i<fact(5*m)+fact(n);i++)
    {
        if(completions2[i]>max_projects)
        max_projects=completions2[i];
    }
    cout << max_projects;
    return 0;
}


