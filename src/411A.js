function main()
{
    var pass = readline();
    if ( pass.length < 5 )
    {
        print("Too weak");
        return;
    }
    var flag1 = true, flag2 = true, flag3 = true;
    for ( i in pass )
    {
        if ( /[A-Z]/.test(pass[i]) )
            flag1 = false;
        if ( /[a-z]/.test(pass[i]) )
            flag2 = false;
        if ( /[0-9]/.test(pass[i]) )
            flag3 = false;
    }
    if ( flag1 || flag2 || flag3 )
    {
        print("Too weak");
        return;
    }
    print("Correct");
}

main();
