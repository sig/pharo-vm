image save/restore
readHeapFromImageFile: f dataBytes: numBytes
	"Read numBytes of image data from f into memory at memoryBaseForImageRead.
	 Answer the number of bytes written."
	<var: #f type: #sqImageFile>
	^self cCode:
			[self
				sq: (self pointerForOop: self memoryBaseForImageRead)
				Image: (self sizeof: #char)
				File: numBytes
				ReadEntireImage: f]
		inSmalltalk:
			[(f	readInto: memory
				startingAt: self memoryBaseForImageRead // 4 + 1
				count: numBytes // 4)
			 * 4]