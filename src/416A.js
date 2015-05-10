function main(){
    var n = parseInt(readline()),
        up = 1<<30;
        low = -up;
    while ( n-- ){
        var tmp = readline().split(" ");
        tmp[1] = parseInt(tmp[1]);
        if ( tmp[2] == "N" ){
            if ( tmp[0] == ">=" ){
                tmp[0] = "<";
            }
            else if ( tmp[0] == "<=" ){
                tmp[0] = ">";
            }
            else if ( tmp[0] == ">" ){
                tmp[0] = "<=";
            }
            else if ( tmp[0] == "<" ){
                tmp[0] = ">=";
            }
        }
        if ( tmp[0] == ">" && tmp[1]+1 > low ){
                low = tmp[1]+1;
        }
        else if ( tmp[0] == ">=" && tmp[1] > low ){
                low = tmp[1];
        }
        else if ( tmp[0] == "<" && tmp[1]-1 < up ){
                up = tmp[1]-1;
        }
        else if ( tmp[0] == "<=" && tmp[1] < up ){
                up = tmp[1];
        }
    }
    if ( up < low ){
        print("Impossible");
    }
    else{
        print(low);
    }
}

main();
