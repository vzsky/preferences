function cplus(){
	fn="`echo "$1"|cut -d. -f1`"
	g++ -std=c++17 $fn.cpp -o $fn
	./$fn
}

function icloud () {
  cd /Users/mb99n/Library/Mobile\ Documents/com~apple~CloudDocs
}

function rust (){
  fn="`echo "$1"|cut -d. -f1`"
  rustc $fn.rs -o $fn
  ./$fn
}

function haskell(){
  fn="`echo "$1"|cut -d. -f1`"
  ghc -o $fn $fn.hs
  ./$fn
}
