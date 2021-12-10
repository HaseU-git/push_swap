# note_push_swap_2021-12-10

## 前回やったこと

<hr>

## 今回やること  

- [x] 引数チェックの部分の修正

- [ ] ルールベースソートの実装  

- [ ] quickソートの実装  

- [ ] 実行手順の実装方法 

- [ ] 引数を連想配列に格納するときにmallocが失敗したらどうするか？

<hr>

## 今回のメモ

### mallocしている部分

- array.cのset_num_array関数
- array.cのlist_to_array関数  
- list_create.cのset_node_first関数  
- list_create.cのset_node_last関数  
- list_create.cのinit_node関数  
- median.cのconvert_to_array関数  

- list_sort.cのinit_process関数  
- list_sort.cのappend_process関数  

- process.cのinit_process関数  
- process.cのset_process_last関数  

### 検討事項

- 実行順序の記憶は連想配列で実装すると、mallocに失敗したときがmainまで戻す必要がある?
→ 全てfreeしてexitしてしまえばいいだけなので、問題ない  

### 今後必要になってくる対応

- argのチェックの部分を見直す必要がある（たいし）に言われた部分  - rraとraの打ち消しによる最適化の必要性  
- 5以下のとき、最小値が上の方にあるのか、下の方にあるのか  
- 5以下のときに、13以上になっていないかチャックすること  

<hr>

## 今回やったこと

引数チェックの部分のシステムを変更した  
ほぼほぼこれで完璧になったはず？？  