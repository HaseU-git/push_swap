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

- [ ] 実行手順を最適化させる  

- [ ] すで整列しているかどうかをチェックする関数  

- [ ] pop_index_processをfreeするものに書き換える
→ popをdeleteにしようとして、freeを使ったらプログラムが動かなくなった

- [ ] ファイルの分割  
→ ls -1の時のprocess_create.cまで分割完了

- [ ] normのクリア  

- [ ] pdfのチェック  

- [ ] 使用禁止関数のチェック  

- [ ] メモリりーく

- [ ] 余計なファイルのチェック

- [ ] エラー処理の挙動のチェック

- [ ] Makefileのリリンクのチェック

- [ ] 余分な関数の削除（show_list / show_ope in main.c など）

<hr>

## 今回のメモ

## 修正必要な箇所

- 2 3 1で入力した時に、手順がうまく保存されていない
→ rraの何か（出力がうまくいっていない模様）
→ writeの出力バッファ数が4ではなく3になってしまっていた。
processにはうまく格納されていた。
 
- nfukadaさんのテスターが5以上の引数で停止してしまった。

- nfukadaさんのテスターが4の時でも止まってしまう時がある  

- nfukadaさんのテスターの./push_swap -345068709 1522740092 627442573 2140594456でと待ってしまう。  
→ 平均値が-1072392315になってしまっていた。  
→ 平均値の算出方法を変更することで解決した。
→ 中央値と平均を間違えていたので、中央値に戻した。  
→ なんかよくわからんけど書き直したらいい感じに動いた。


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

## レビュー文章

>review項目
>
>Mandatory part
>Reminder : Remember that for the duration of the defence, no segfault, nor other unexpected, premature, uncontrolled or unexpected termination of the program, else the final grade is 0. Use the appropriate flag. This rule is active thoughout the whole defence.
>
>Memory leaks
>
>Throughout the defence, pay attention to the amount of memory
>used by push_swap (using the command top for example) in order
>to detect any anomalies and ensure that allocated memory is
>properly freed. If there is one memory leak (or more), the final
>grade is 0.
>Error management
>
>In this section, we'll evaluate the push_swap's error management.
>If at least one fails, no points will be awarded for this
>section. Move to the next one.
>
>- Run push_swap with non numeric parameters. The program must
>display "Error".
>
>- Run push_swap with a duplicate numeric parameter. The program
>must display "Error".
>
>- Run push_swap with only numeric parameters including one greater
>than MAXINT. The program must display "Error".
>
>- Run push_swap without any parameters. The program must not
>display anything and give the prompt back.
>Push_swap - Identity test
>
>In this section, we'll evaluate push_swap's behavior when given
>a list, which has already been sorted. Execute the following 3
>tests. If at least one fails, no points will be awarded for this
>section. Move to the next one.
>
>- Run the following command "$>./push_swap 42". The program
>
>should display nothing (0 instruction).
>
>- Run the following command "$>./push_swap 0 1 2 3". The
>program should display nothing (0 instruction).
>
>- Run the following command "$>./push_swap 0 1 2 3 4 5 6 7 8
>9". The program should display nothing (0 instruction).
>Push_swap - Simple version
>
>If the following test fails, no points will be awarded for this
>section. Move to the next one. Use the checker binary given on the
>attachments.
>
>- Run "$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG".
>Check that the checker program displays "OK" and that the
>size of the list of instructions from push_swap is 2 OR 3.
>Otherwise the test fails.
>Another simple version
>
>Execute the following 2 tests. If at least one fails, no points
>will be awarded for this section. Move to the next one. Use the checker
>binary given on the attachments.
>
>- Run "$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG".
>Check that the checker program displays "OK" and that the
>size of the list of instructions from push_swap isn't more
>than 12. Kudos if the size of the list of instructions is 8.
>
>- Run "$>ARG="<5 random values>"; ./push_swap $ARG | ./checker_OS
>$ARG" and replace the placeholder by 5 random valid values.
>Check that the checker program displays "OK" and that the
>size of the list of instructions from push_swap isn't more
>than 12. Otherwise this test fails. You'll have to
>specifically check that the program wasn't developed to only
>answer correctly on the test included in this scale. You
>should repeat this test couple of times with several
>permutations before you validate it.
>Push_swap - Middle version
>
>If the following test fails, no points will be awarded for this
>section. Move to the next one. Move to the next one. Use the checker
>binary given on the attachments.
>
>- Run "$>ARG="<100 random values>"; ./push_swap $ARG |
>
>./checker_OS $ARG" and replace the placeholder by 100 random
>valid values. Check that the checker program displays "OK"
>and that the size of the list of instructions.
>Give points in accordance:
>- less than 700: 5
>- less than 900: 4
>- less than 1100: 3
>- less than 1300: 2
>- less than 1500: 1
>You'll have to specifically check that the program wasn't developed to
>only answer correctly on the test included in this scale.
>You should repeat this test couple of times with several
>permutations before you validate it.
>Rate it from 0 (failed) through 5 (excellent)
>
>Push_swap - Advanced version
>
>If the following test fails, no points will be awarded for this
>section. Move to the next one. Move to the next one. Use the checker
>binary given on the attachments.
>
>- Run "$>ARG="<500 random values>"; ./push_swap $ARG |
>./checker_OS $ARG" and replace the placeholder by 500 random
>valid values (One is not called John/Jane Script for
>nothing). Check that the checker program displays "OK" and
>that the size of the list of instructions
>- less than 5500: 5
>- less than 7000: 4
>- less than 8500: 3
>- less than 10000: 2
>- less than 11500: 1
>You'll have to specifically check that the program wasn't developed to
>only answer correctly on the test included in this scale.
>You should repeat this test couple of times with several
>permutations before you validate it.
>Rate it from 0 (failed) through 5 (excellent)
>
>Bonus
>Reminder : Remember that for the duration of the defence, no segfault, nor other unexpected, premature, uncontrolled or unexpected termination of the program, else the final grade is 0. Use the appropriate flag. This rule is active throughout the whole defence. We will look at your bonuses if and only if your mandatory part is EXCELLENT. This means that you must complete the mandatory part, beginning to end, and your error management needs to be flawless, even in cases of twisted or
>
>bad usage. So if the mandatory part didn't score all the point during this defence bonuses will be totally IGNORED.
>
>Checker program - Error management
>
>In this section, we'll evaluate the checker's error management.
>If at least one fails, no points will be awarded for this
>section. Move to the next one.
>
>- Run checker with non numeric parameters. The program must
>display "Error".
>
>- Run checker with a duplicate numeric parameter. The program
>must display "Error".
>
>- Run checker with only numeric parameters including one greater
>than MAXINT. The program must display "Error".
>
>- Run checker without any parameters. The program must not
>display anything and give the prompt back.
>
>- Run checker with valid parameters, and write an action that
>doesn't exist during the instruction phase. The program must
>display "Error".
>
>- Run checker with valid parameters, and write an action with
>one or several spaces before and/or after the action during
>the instruction phase. The program must display "Error".
>Checker program - False tests
>
>In this section, we'll evaluate the checker's ability to manage
>a list of instructions that doesn't sort the list. Execute the
>following 2 tests. If at least one fails, no points will be
>awarded for this section. Move to the next one.
>
>Don't forget to press CTRL+D to stop reading during the
>intruction phase.
>
>- Run checker with the following command "$>./checker 0 9 1 8 2
>7 3 6 4 5" then write the following valid action list "[sa,
>pb, rrr]". Checker should display "KO".
>
>- Run checker with a valid list as parameter of your choice then
>write a valid instruction list that doesn't order the
>integers. Checker should display "KO". You'll have to
>
>end, and your error management needs to be flawless, even in cases of twisted or cspecifically check that the program wasn't developed to only
>answer correctly on the test included in this scale. You
>should repeat this test couple of times with several
>permutations before you validate it.
>Checker program - Right tests
>
>In this section, we'll evaluate the checker's ability to manage
>a liss of instructions that sort the list. Execute the following
>2 tests. If at least one fails, no points will be awarded for
>this section. Move to the next one.
>
>Don't forget to press CTRL+D to stop reading during the
>instruction phase.
>
>- Run checker with the following command "$>./checker 0 1 2"
>then press CTRL+D without writing any instruction. The program
>should display "OK".
>
>- Run checker with the following command "$>./checker 0 9 1 8 2"
>then write the following valid action list "[pb, ra, pb, ra,
>sa, ra, pa, pa]". The program should display "OK".
>
>- Run checker with a valid list as parameter of your choice then
>write a valid instruction list that order the integers.
>Checker must display "OK". You'll have to specifically check
>that the program wasn't developed to only answer correctly on
>the test included in this scale. You should repeat this test
>couple of times with several permutations before you validate
>it.
