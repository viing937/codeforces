function main()
{
    var tmp;
    tmp = readline().split(" ").map(function (x) { return parseInt(x); });
    var n = tmp[0],
        m = tmp[1];
    var a = readline().split(" ").map(function (x) { return parseInt(x); });
    var y = 0;
    while ( m-- )
    {
        tmp = readline().split(" ").map(function (x) { return parseInt(x); });
        if ( tmp[0] == 1 )
        {
            a[tmp[1]-1] = tmp[2]-y;
        }
        else if ( tmp[0] == 2 )
        {
            y += tmp[1];
        }
        else if ( tmp[0] == 3 )
        {
            print(a[tmp[1]-1]+y);
        }
    }
}

main();
