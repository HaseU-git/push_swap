# note_push_swap_2021-12-11

## 前回やったこと

- [x] 引数チェックの部分を完成させる

<hr>

## 今回やること  


- [ ] arg.cのファイルを分割する

- [x] ルールベースソートの実装  

- [x] quickソートの実装  

- [ ] 引数を連想配列に格納するときにmallocが失敗したらどうするか？

- [ ] 実行手順を最適化させる  

- [ ] 実行手順を表示させるための関数  

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
- pdfのチェック（pdfが修正され、何も表示するな、と明記されましたhttps://discord.com/channels/691903146909237289/691908977918738453/919762773154619432）
- フカダさんのテスターをやる（https://github.com/nafuka11/push_swap_tester）  
- Makefileを作成する(https://github.com/ohtaketaishi/push_swap/blob/main/Makefile)

<hr>

## 今回やったこと

最適化以外の部分に関してはほとんど完璧になった気がする  
→ 手順もoperationにきちんと格納されている模様

メモリりーくもしてなさそう  
