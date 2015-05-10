function main(){
    var tmp = readline().split(" ").map(function (x) { return parseInt(x); });
    var t = tmp[0],
        sx = tmp[1],
        sy = tmp[2],
        ex = tmp[3],
        ey = tmp[4];
    tmp = readline();
    var ans = 0;
    if ( sx > ex ){
        var i;
        var cnt = sx - ex;
        for ( i = 0; i < tmp.length && cnt > 0; i++ ){
            if ( tmp[i] == "W" ){
                cnt--;
            }
        }
        if ( cnt > 0 ){
            print(-1);
            return;
        }
        if ( ans < i ){
            ans = i;
        }
    }
    else if ( sx < ex ){
        var i;
        var cnt = ex - sx;
        for ( i = 0; i < tmp.length && cnt > 0; i++ ){
            if ( tmp[i] == "E" ){
                cnt--;
            }
        }
        if ( cnt > 0 ){
            print(-1);
            return;
        }
        if ( ans < i ){
            ans = i;
        }
    }
    if ( sy > ey ){
        var i;
        var cnt = sy - ey;
        for ( i = 0; i < tmp.length && cnt > 0; i++ ){
            if ( tmp[i] == "S" ){
                cnt--;
            }
        }
        if ( cnt > 0 ){
            print(-1);
            return;
        }
        if ( ans < i ){
            ans = i;
        }
    }
    else if ( sy < ey ){
        var i;
        var cnt = ey - sy;
        for ( i = 0; i < tmp.length && cnt > 0; i++ ){
            if ( tmp[i] == "N" ){
                cnt--;
            }
        }
        if ( cnt > 0 ){
            print(-1);
            return;
        }
        if ( ans < i ){
            ans = i;
        }
    }
    print(ans);
}

main();
