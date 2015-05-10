function main(){
    var tmp = readline().split(" ").map(function (x){ return parseInt(x); });
    var x = tmp[0],
        t = tmp[1],
        a = tmp[2],
        b = tmp[3],
        da = tmp[4],
        db = tmp[5];
    if ( x == 0 ){
        print("YES");
        return;
    }
    for ( var i = 0; i < t; i++ ){
        for ( var j = 0; j < t; j++ ){
            if ( a+b == x || a == x || b == x ){
                print("YES");
                return;
            }
            b -= db;
        }
        a -= da;
        b = tmp[3];
    }
    print("NO");
}

main();
