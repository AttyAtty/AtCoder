# 入力
H, W = map(int, input().split())
# split()は空白ごとに分割してリストにする関数
# split(',')はカンマごとに分割する関数
# map(int, input().split())は、入力された文字列を整数に変換する関数．
# このとき，リストではないが，リストみたいに値が保管されていて，その先頭から順番にH,Wに割り当てられていく
# リストにしたいなら、list(map(int, input().split()))とする
A = [list(map(int, input().split())) for _ in range(H)]
# 2次元リストAを作成．Wを書かずとも，mapは入力の行全体に対して行っているので，自然とwの長さになる

# 前処理
yoko = list(map(sum, A))
tate = list(map(sum, zip(*A)))# zip(*A) は、A の転置（列ごとのタプル）を作成。

# 各マス
for i in range(H):
    print(' '.join(map(lambda j: str(yoko[i] + tate[j] - A[i][j]), range(W))))
# 各行で j in range(W) に対して.ラムダ関数を使っている
# map(...) → 文字列のリストになる
# ' '.join(...) → それらを空白でつなぐ