# note_push_swap_2021-09-07

## 今日やること  

1. スタックAからスタックBに半分持っていく  


## スタックAからスタックBに持っていく

双方向連結リスト二つを受け取って、比較していく関数  

```C

void put_larger_halfto_b(t_node *stack_a t_node *stack_b)

```


## 疑問点
ソートの際に操作したものはどこに記録しておくか？  
→ 連結リストでつなげておく。  




## 問題点
- メモリリーク  