make
echo "\nTEST ALL len=3 case"
make test ARG="1 2 3"
make test ARG="1 3 2"
make test ARG="2 3 1"
make test ARG="2 1 3"
make test ARG="3 1 2"
make test ARG="3 2 1"

echo "\nTEST ALL len=5 case"
make test ARG="1 2 3 4 5"
make test ARG="1 2 3 5 4"
make test ARG="1 2 4 3 5"
make test ARG="1 2 4 5 3"
make test ARG="1 2 5 3 4"
make test ARG="1 2 5 4 3"
make test ARG="1 3 2 4 5"
make test ARG="1 3 2 5 4"
make test ARG="1 3 4 2 5"
make test ARG="1 3 4 5 2"
make test ARG="1 3 5 2 4"
make test ARG="1 3 5 4 2"
make test ARG="1 4 2 3 5"
make test ARG="1 4 2 5 3"
make test ARG="1 4 3 2 5"
make test ARG="1 4 3 5 2"
make test ARG="1 4 5 2 3"
make test ARG="1 4 5 3 2"
make test ARG="1 5 2 3 4"
make test ARG="1 5 2 4 3"
make test ARG="1 5 3 2 4"
make test ARG="1 5 3 4 2"
make test ARG="1 5 4 2 3"
make test ARG="1 5 4 3 2"
make test ARG="2 1 3 4 5"
make test ARG="2 1 3 5 4"
make test ARG="2 1 4 3 5"
make test ARG="2 1 4 5 3"
make test ARG="2 1 5 3 4"
make test ARG="2 1 5 4 3"
make test ARG="2 3 1 4 5"
make test ARG="2 3 1 5 4"
make test ARG="2 3 4 1 5"
make test ARG="2 3 4 5 1"
make test ARG="2 3 5 1 4"
make test ARG="2 3 5 4 1"
make test ARG="2 4 1 3 5"
make test ARG="2 4 1 5 3"
make test ARG="2 4 3 1 5"
make test ARG="2 4 3 5 1"
make test ARG="2 4 5 1 3"
make test ARG="2 4 5 3 1"
make test ARG="2 5 1 3 4"
make test ARG="2 5 1 4 3"
make test ARG="2 5 3 1 4"
make test ARG="2 5 3 4 1"
make test ARG="2 5 4 1 3"
make test ARG="2 5 4 3 1"
make test ARG="3 1 2 4 5"
make test ARG="3 1 2 5 4"
make test ARG="3 1 4 2 5"
make test ARG="3 1 4 5 2"
make test ARG="3 1 5 2 4"
make test ARG="3 1 5 4 2"
make test ARG="3 2 1 4 5"
make test ARG="3 2 1 5 4"
make test ARG="3 2 4 1 5"
make test ARG="3 2 4 5 1"
make test ARG="3 2 5 1 4"
make test ARG="3 2 5 4 1"
make test ARG="3 4 1 2 5"
make test ARG="3 4 1 5 2"
make test ARG="3 4 2 1 5"
make test ARG="3 4 2 5 1"
make test ARG="3 4 5 1 2"
make test ARG="3 4 5 2 1"
make test ARG="3 5 1 2 4"
make test ARG="3 5 1 4 2"
make test ARG="3 5 2 1 4"
make test ARG="3 5 2 4 1"
make test ARG="3 5 4 1 2"
make test ARG="3 5 4 2 1"
make test ARG="4 1 2 3 5"
make test ARG="4 1 2 5 3"
make test ARG="4 1 3 2 5"
make test ARG="4 1 3 5 2"
make test ARG="4 1 5 2 3"
make test ARG="4 1 5 3 2"
make test ARG="4 2 1 3 5"
make test ARG="4 2 1 5 3"
make test ARG="4 2 3 1 5"
make test ARG="4 2 3 5 1"
make test ARG="4 2 5 1 3"
make test ARG="4 2 5 3 1"
make test ARG="4 3 1 2 5"
make test ARG="4 3 1 5 2"
make test ARG="4 3 2 1 5"
make test ARG="4 3 2 5 1"
make test ARG="4 3 5 1 2"
make test ARG="4 3 5 2 1"
make test ARG="4 5 1 2 3"
make test ARG="4 5 1 3 2"
make test ARG="4 5 2 1 3"
make test ARG="4 5 2 3 1"
make test ARG="4 5 3 1 2"
make test ARG="4 5 3 2 1"
make test ARG="5 1 2 3 4"
make test ARG="5 1 2 4 3"
make test ARG="5 1 3 2 4"
make test ARG="5 1 3 4 2"
make test ARG="5 1 4 2 3"
make test ARG="5 1 4 3 2"
make test ARG="5 2 1 3 4"
make test ARG="5 2 1 4 3"
make test ARG="5 2 3 1 4"
make test ARG="5 2 3 4 1"
make test ARG="5 2 4 1 3"
make test ARG="5 2 4 3 1"
make test ARG="5 3 1 2 4"
make test ARG="5 3 1 4 2"
make test ARG="5 3 2 1 4"
make test ARG="5 3 2 4 1"
make test ARG="5 3 4 1 2"
make test ARG="5 3 4 2 1"
make test ARG="5 4 1 2 3"
make test ARG="5 4 1 3 2"
make test ARG="5 4 2 1 3"
make test ARG="5 4 2 3 1"
make test ARG="5 4 3 1 2"
make test ARG="5 4 3 2 1"

echo "\nTEST 5 random len=25"
make test ARG="`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`"

echo "\nTEST 5 random len=50"
make test ARG="`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`"

echo "\nTEST 5 random len=100"
make test ARG="`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`"

echo "\nTEST 5 random len=500"
make test ARG="`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`"
make test ARG="`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`"
