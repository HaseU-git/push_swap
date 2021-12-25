# note_push_swap_2021-12-11

## 前回やったこと

- [x] 手順の連結リストからインデックス指定でpopする関数  

- [x] 手順の連結リストからインデックス指定でinsertする関数

- [x] 3こいかの時にquicksortではなく、rule_sortにするようにした。

- [x] t_opeにDUMMYを追加した。
→ 最適化の部分でsaとdummyが同じになってしまって、おかしな挙動になったため。

<hr>

## 今回やること  

- [ ] arg.cのファイルを分割する

- [ ] 引数を連想配列に格納するときにmallocが失敗したらどうするか？

- [ ] 実行手順を最適化させる  

- [ ] すで整列しているかどうかをチェックする関数  

- [ ] pop_index_processをfreeするものに書き換える

<hr>

## 今回のメモ

## 修正必要な箇所

- 2 3 1で入力した時に、手順がうまく保存されていない
→ rraの何か（出力がうまくいっていない模様）
→ writeの出力バッファ数が4ではなく3になってしまっていた。
processにはうまく格納されていた。
 
### 手順の最適化方法

#### 必要になる関数

- indexをカウントする
- indexを指定してpopできる関数
- indexをカウントして挿入できる関数
	挿入する時に必要になる手順(index=2に挿入したい場合)
	1. ptrをindexに揃える
	2. ptr->prev->next = new
	3. new->prev = ptr->prev
	4. ptr->prev = new
	5. new->next = ptr

### リスト

- [x] RA→RBのRR化
	1. indexをカウントしておく
	2. RAかどうかをチェック  
	3. 次がRBかどうかをチェック  
	4. RA→RBだったら以下を実行する
	5. indexの部分を取り出す（RA）
	6. RAを削除する  
	7. indexの部分を取り出す（RB）
	8. RBを削除する  
	9. indexの部分にRRを挿入する

- [x] RB→RAのRR化

- [x] RRA→RRBのRRR化

- [x] RRB→RRAのRRR化

- [x] SA→SBのSS化

- [x] SB→SAのSS化

- [x] RA→RRAの打ち消し
	1. indexをカウントしておく
	2. RAかどうかをチェック  
	3. 次がRRAかどうかをチェック  
	4. RA→RRAだったら以下を実行する
	5. indexの部分を取り出す（RA）
	6. RAを削除する  
	7. indexの部分を取り出す（RRA）
	8. RRAを削除する  

- [x] RRA→RAの打ち消し

- [x] RB→RRBの打ち消し

- [x] RRB→RBの打ち消し

- [x] PA→PBの打ち消し

- [x] PB→PAの打ち消し

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

## 提出前に気をつけること

pdfに乗ってないファイルを乗っけちゃう  

Makefileをリリンクしないようにする  

実行ファイルの名前が違うとヤバス  

normは気をつける（バージョン3.3.2）  