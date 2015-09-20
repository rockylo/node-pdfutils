/*
 * PdfiumEngine.h
 * Copyright (C) 2014 tox <tox@rootkit>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef POPPLERENGINE_H
#define POPPLERENGINE_H

#include <node.h>
#include <v8.h>
#include "../PdfEngineFactory.h"
#include <glib/poppler.h>

class PdfiumEngine : public PdfEngine {
public:
	static void Init();
	PdfiumEngine();
	~PdfiumEngine();

	static PdfEngine *NewInstance() {
		return new PdfiumEngine();
	}

	virtual char *openFromData(char *data, size_t length);
	virtual char *openFromPath(char *src);
	virtual void fillDocument(PdfDocument *document);
	virtual void fillPage(int index, PdfPage *page);
	virtual void close();
	virtual char* renderPage(int index, PdfRenderFormat format, PdfExportPageWorker *writer);
	virtual char* savePdf(PdfPage *pages, PdfSaveWorker *writer);



private:
};

#endif /* !POPPLERENGINE_H */