# pointer
## ポインタ
- 変数に&を程起用するとその変数のアドレス（ポインタ）を得ることができる
- ポインタ変数Aが別の変数Bへのポインタを保持している時，AがBをさしている（A-\>B）という
- ポインタに\*演算子をつけると指している先のデータを保持するようになる(\*AはBの情報を持つ)

## ポインタ演算
- ポインタにn加算するとポインタは(そのポインタが指す型)\*nだけ進む


## []は配列とは無関係
p = &array[0];をp = array;と書いたからといって配列の先頭要素へのポインタを表しているわけではない
式の中では配列は「その先頭要素へのポインタ」に読み替えられる
後ろに[]が付くかどうかは関係ない
p[i]は\*(p+i)の簡便記法．ただそれだけ(一種のsyntax sugar)
p[i]を使え

ただし宣言の方での[]は全く違う意味を持つことに注意
### 復習
p45~p48 nullポインタ