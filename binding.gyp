{
	"targets": [{
		"target_name": "pdfutils",
		"sources": [
			"src/PdfController.cpp",
			"src/PdfPageController.cpp",
			"src/PdfDocument.cpp",
			"src/PdfEngine.cpp",
			"src/PdfEngineFactory.cpp",
			"src/init.cpp",
			"src/v8utils.cpp",
		],
		"cflags": [
			"-fPIC"
		],
	}, {
		"target_name": "popplerEngine",
		"sources": [
			"src/PdfDocument.cpp",
			"src/PdfEngine.cpp",
			"src/PdfEngineFactory.cpp",
			"src/PdfPageController.cpp",
			"src/v8utils.cpp",
			"src/poppler/PopplerEngine.cpp",
		],
		"xcode_settings": {
			"OTHER_CFLAGS": [
				"<!@(pkg-config --cflags poppler-glib)"
			],
		},
		"cflags": [
			"<!@(pkg-config --cflags poppler-glib) -fPIC"
		],
		"ldflags": [
			"<!@(pkg-config --libs poppler-glib)"
		],
		"libraries": [
			"<!@(pkg-config --libs poppler-glib)"
		]
	}]
}
