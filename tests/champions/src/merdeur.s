	.name "Merdeur"
	.comment "Il vous insulte"

	sti r1, %:hi, %1

hi:	live %234
	ld %109, r2
	ld %101, r3
	ld %114, r4
	ld %100, r5
	ld %101, r6
	ld %10, r7
	aff r2
	aff r3
	aff r4
	aff r5
	aff r6
	aff r7
	sub r3, r6, r8
	zjmp %:hi
