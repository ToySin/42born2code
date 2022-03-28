echo "Wrong usage: "
./so_long
echo

echo "not exist file: "
./so_long map/not_exist_file
echo

echo "empty map file: "
./so_long map/empty_map.ber
echo

echo "Multiple player spon site(P) exist: "
./so_long map/multi_P.ber
echo

echo "Collection(C) is not exist: "
./so_long map/no_C.ber
echo

echo "Exit(E) is not exist: "
./so_long map/no_E.ber
echo

echo "Player spon site(P) is not exist: "
./so_long map/no_P.ber
echo

echo "Map is not rectangle: "
./so_long map/not_rectangle.ber
echo

echo "Map is not surrounded by walls: "
./so_long map/not_surrounded.ber
