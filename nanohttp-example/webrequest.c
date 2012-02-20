#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/nanohttp.h>

#define XML_URL "http://www.jiwakreatif.com/demo/libxml/xml_test.php"

void GetXMLHttp();
void FetchXMLFile();

int main(int argc, char **argv) {
	printf("nanohttp example: %s\n", XML_URL);
	
#if defined(LIBXML_HTTP_ENABLED)
	printf("XML http enabled\n");
#endif
	
	//FetchXMLFile();
	GetXMLHttp();
	
	return 0;
}

void GetXMLHttp() {
	void * Ctxt;
	char *contentType;
	
	xmlNanoHTTPInit();
	
	Ctxt = xmlNanoHTTPOpen(XML_URL, &contentType);

	if (Ctxt == 0)
		printf("ERROR: xmlNanoHTTPOpen() == 0\n");

	if (xmlNanoHTTPReturnCode(Ctxt) != 200)
		printf("ERROR: HTTP Code != OK\n");

	// open output file
	FILE *fp;
	fp=fopen("test_get.xml","w");
	

	// Write to file
	const int Size = 2048;
	char Buffer[Size];
	int Count;

	while ((Count = xmlNanoHTTPRead(Ctxt, Buffer, Size)) > 0)
		fprintf(fp,"%s",Buffer);	
		//File.write(Buffer, Count);
		
	fclose(fp);

	if (Count == 0)
		printf("STATUS: Connection closed\n");

	if (Count == -1)
		printf("ERROR: xmlNanoHTTPRead() == -1\n");
	
		
	// Free ressources
	xmlFree(contentType);
	xmlNanoHTTPClose(Ctxt);
	xmlNanoHTTPCleanup();
}

// not working in mingw. test.xml file is not saved properly as text file.
void FetchXMLFile() {
#if defined(LIBXML_HTTP_ENABLED)
    int ret_val;
    char *contentType; /* if available the Content-Type information will be returned at that location */

	xmlNanoHTTPInit();
	
	ret_val = xmlNanoHTTPFetch(XML_URL, "test.xml", &contentType);
	
	printf("ContentType: %s\n",contentType);
	printf("Retval %d\n", ret_val);
	
	xmlNanoHTTPCleanup();
#endif
}
