digital = {'0'=>'O-|-OOOO', '1'=>'O-|O-OOO', '2'=>'O-|OO-OO', '3'=>'O-|OOO-O', '4'=>'O-|OOOO-',\
           '5'=>'-O|-OOOO', '6'=>'-O|O-OOO', '7'=>'-O|OO-OO', '8'=>'-O|OOO-O', '9'=>'-O|OOOO-'}
n = gets.chomp.split('')
n.reverse.each{|i| puts digital[i]}
