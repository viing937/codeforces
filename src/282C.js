function main(){
    var a = readline(),
        b = readline();
    if ( a.length != b.length ){
        print("NO");
        return;
    }
    if ( a == b ){
        print("YES");
        return;
    }
    if ( a.match(/1/) && b.match(/1/) ){
        print("YES");
    }
    else{
        print("NO");
    }
}

main();
