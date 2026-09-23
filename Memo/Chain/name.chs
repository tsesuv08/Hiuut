%inc `cslio.chh`

[	(int)main<> public
	[	`str` -> (str)tpe

		`Hello` -> (&tpe)hello
		`hello` -> (&tpe)var

		`csl` -> (&tpe)nsp
		`out` -> (&tpe)func

		&nsp:&func<&var>

		func + `ln` -> func
		`Hallo` -> &var

		&nsp:&func<&var>

		; この構文が輝くのが、C言語でswitch->関数呼び出しとしていた物を、変数の書き換えで呼び出し1回だけと言う書き方に出来る事
		;
		; switch(input)
		; {	case 'a':
		; 		add(num1, num2);
		; 		break;
		; 	case 's':
		; 		sub(num1, num2);
		; 		break;
		; ...
		; }
		;が
		; null -> (str)func
		; if<input = 'a'>
		; [	`add` -> func
		; ]
		; elif<input ='s'>
		; [	`sub` -> func
		; ]
		; ...
		; &func<num1, num2>

		ret<0>
	]
] # (mdl)name
