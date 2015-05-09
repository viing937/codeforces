function main()
{
    var s = readline();
    var ans = "";
    var flag = false,
        quote = false;
    for ( var i = 0; i < s.length; i++ )
    {
        if ( s[i] == "\"" )
        {
            if ( quote )
            {
                print("<"+ans+">");
                ans = "";
            }
            quote = !quote;
        }
        else if ( !quote && s[i] == " " )
        {
            if ( ans.length )
            {
                print("<"+ans+">");
                ans = "";
            }
        }
        else
        {
            ans += s[i];
        }
    }
    if ( ans != "" )
        print("<"+ans+">");
}

main();
