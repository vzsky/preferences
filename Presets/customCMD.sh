function cplus(){
	fn="`echo "$1"|cut -d. -f1`"
	g++ -std=c++17 $fn.cpp -o $fn
	./$fn
}

function haskell(){
  fn="`echo "$1"|cut -d. -f1`"
  ghc -o $fn $fn.hs
  ./$fn
}

function word(){
	echo Word count: $(wc -w).
}
