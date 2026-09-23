; Chain introduction
; intro.chs

%inc `cslio.chh`
%inc `strs.chh`

[	(int)main<> public
	[	(str)s

		to<scmp<s, `cmd_end_`>> ; while
		[	csl:in<> -> s ; <-向きじゃないのはそっちだと関数の引数の最初の要素に単項演算子-が付いている場合との区別がめんどい為。
						  ; ->向きならば先ず関数呼び出しがあったかどうかで判別出来るし、抑単項演算子-と関数呼び出し末尾>が普通のコードで連続しない・している場合エラーだし。
			putchrl<s>
		]

		ret<0>
	]

	(bool)putchrl<(str)s>
	[	if<!strs:valid<s>>
			trp<$400> ; 割り込み―。215の奴。

		(int)size <- strs:slen<s>

		for<0 -> (int)i, i ? size, i++> ; i ? size は i < size.
		[	csl:put<strs:getc<s, i>> ; s_iとしてはいけない、(chr*)sや(chr)s_(10)とstr型は別物。配列アクセスs_iはエラー。
			csl:out<`\n`>
		]

		ret<true>
	]
] # (mdl)intro
