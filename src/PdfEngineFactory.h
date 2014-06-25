/*
 * PdfEngineFactory.h
 * Copyright (C) 2014 tox <tox@rootkit>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef PDFENGINEFACTORY_H
#define PDFENGINEFACTORY_H

#include <v8.h>
#include <node.h>
#include "PdfEngine.h"

#define PDF_ENGINE(n, ...) \
void n ## _init__(v8::Handle<v8::Object> exports) { \
	new PdfEngineFactory(exports, #n, __VA_ARGS__); \
} \
NODE_MODULE(n ## Engine, n ## _init__)

typedef PdfEngine *(*PdfEngineInit)(void);

/**
 * @brief Factory Class for PDF Engines
 *
 * This class provides functionality to reuse the node.js module system
 * to dynamicly load multiple PdfEngines.
 */
class PdfEngineFactory : public node::ObjectWrap {
private:
	PdfEngineInit init;
public:
	PdfEngineFactory(v8::Handle<v8::Object> &exports,
			const char *name,
			// Macro args:
			const char *license,
			const PdfEngineInit pdfInit);

	PdfEngine *newInstance();
};

#endif /* !PDFENGINEFACTORY_H */
