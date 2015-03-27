# coding: utf-8
m = [['']*6 for i in range(6)]
for i in range(1,5):
    m[i] = [''] + list(input()) + ['']
for i in range(1,5):
    for j in range(1,5):
        if (m[i-1][j]=='#' and m[i-1][j-1]=='#' and m[i][j-1]=='#')\
        or (m[i-1][j]=='.' and m[i-1][j-1]=='.' and m[i][j-1]=='.')\
        or (m[i][j-1]=='#' and m[i+1][j-1]=='#' and m[i+1][j]=='#')\
        or (m[i][j-1]=='.' and m[i+1][j-1]=='.' and m[i+1][j]=='.')\
        or (m[i][j+1]=='#' and m[i-1][j+1]=='#' and m[i-1][j]=='#')\
        or (m[i][j+1]=='.' and m[i-1][j+1]=='.' and m[i-1][j]=='.')\
        or (m[i][j+1]=='#' and m[i+1][j+1]=='#' and m[i+1][j]=='#')\
        or (m[i][j+1]=='.' and m[i+1][j+1]=='.' and m[i+1][j]=='.'):
            print('YES')
            exit()
print('NO')
