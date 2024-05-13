.name "Abel2"
.comment "L'autre Abel"

	sti r1, %:hi, %1

hi:	live %234
	ld %0, r3
	zjmp %:hi
