# note_push_swap_2021-12-11

## 前回やったこと

- [x] ファイルの分割

- [x] 実行手順を最適化させる  


<hr>

## 今回やること  


- [x] すで整列しているかどうかをチェックする関数  

- [ ] pop_index_processをfreeするものに書き換える
→ popをdeleteにしようとして、freeを使ったらプログラムが動かなくなった

- [x] normのクリア  

- [ ] pdfのチェック  

- [ ] 使用禁止関数のチェック  
→ printf2期をつける
（nm -u push_swap）

- [x] メモリりーく
→ optimize_process()を使用すると、7ことかでやった時にメモリりーくしてしまう
→ 手順の最適化は新しくmallocせずにoperationを書き換えることで実装する  
→ optimize_processの実装方法をmallocを使用しない形に変更。  
indexとポインタをごっちゃにしていたためセグフォが起きてしまっていた。
→ 改善済み。

- [ ] mainの初期値を0にする必要はないかどうかをnorm確認する

- [ ] 余計なファイルのチェック

- [ ] エラー処理の挙動のチェック
→ 何も入力されていなかったら何も表示しない  

- [ ] Makefileのリリンクのチェック

- [ ] 余分な関数の削除（show_list / show_ope in main.c など）

- [ ] 改行の仕方が正しいのかどうか確認する（\)
→ \はなくても良いらしい  

- [ ] レビュー項目を確認する  [

- [ ] mallocしているところをきちんとfreeしてからexitしているか？？[
→ そもそもexitしているかどうか？  

- [ ] exitの引数を1にするのか0にするのか確認する[

- [ ] ifの中に関数を入れるのはOK？[

<hr>

## 今回のメモ


### 今後必要になってくる対応

- pdfのチェック（pdfが修正され、何も表示するな、と明記されましたhttps://discord.com/channels/691903146909237289/691908977918738453/919762773154619432）

<hr>

## 今回やったこと


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