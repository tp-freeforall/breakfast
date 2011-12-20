#!/usr/bin/env python
import sys
try:
    from lxml import etree
except ImportError:
    sys.stderr.write("""This tool requires lxml. Use

# easy_install --allow-hosts=lxml.de,*.python.org lxml

to install it.""")
    sys.exit(1)

PRIMITIVE_FIELDTYPES = ["nx_uint8_t", 
    "nx_uint16_t", 
    "nx_int8_t",
    "nx_int16_t", 
    "char"]


class FieldType(object):
    def __init__(self):
        pass

    def structStr(self):
        pass

class NXUint8(FieldType):
    def structStr(self):
        return "!B"

class NXInt8(FieldType):
    def structStr(self):
        return "!b"

class NXUint16(FieldType):
    def structStr(self):
        return "!H"

class NXInt16(FieldType):
    def structStr(self):
        return "!h"

class Char(FieldType):
    def structStr(self):
        return "c"

class FieldDef(object):
    """Abstract structure of a single field. Can be converted into
    one field in a nesC-compatible struct declaration. Parses
    subsection of record.
    """
    def __init__(self, fe):
        self.fTypeName = fe.xpath("@type")[0]
        self.fLabel = fe.xpath("@label")[0]
        varLen = fe.xpath("@varLen")
        maxLen = fe.xpath("@maxLen")

        if maxLen:
            self.maxLen = int(maxLen[0])
        else:
            self.maxLen = None

        if varLen and varLen[0] == "true":
            self.varLen = True
        else:
            self.varLen = False
        #optimization: if fixed-length (composed of a fixed number of fixed-length
        #  fields), can generate fmt string statically

    def fieldStr(self):
        """Get a string for how this field is represented in nesC.
        """
        s = ""
        if self.varLen:
            s += "nx_uint8_t %s_len, " %(self.fLabel)
        s += "%s %s"%(self.fTypeName, self.fLabel)
        if self.maxLen:
            s += "[%d]"%self.maxLen
        return s

    def parseBlob(self, blob):
        """Consume a portion of a record, returning the logical values
        it contains from this field and the remaining data in the
        blob.
        """
        #TODO: consume data from start of blob belonging to this field
        #TODO: return ([vals], remaining) tuple
        pass

    def __str__(self):
        return self.fTypeName+" "+self.fLabel \
          + ("[%d]"%self.maxLen if self.maxLen else "") \
          + ("*" if self.varLen else "")

class StructDef(object):
    """Abstract structure of a multi-field record (or sub-record). Can
    be converted to nesC-compatible nx_struct typedef. Can parse
    subsection of physical record recursively according to field
    definitions.
    """

    def __init__(self, structElement):
        self.name = structElement.xpath("@name")[0]
        self.primary = structElement.xpath("@primary") and structElement.xpath("@primary")[0] == "true"
        self.fields = [FieldDef(f) for f in structElement.xpath("field") ]
        self.dependencyNames = [field.fTypeName for field in self.fields
            if field.fTypeName not in PRIMITIVE_FIELDTYPES]
    
    def linkDependencies(self, structMap):
        for f in self.fields:
            if f.fTypeName in structMap:
                f.fType = structMap[f.fTypeName]

    def cStructStr(self):
        fs = ", \n".join([f.fieldStr() for f in self.fields])
        return ("typedef nx_struct %s { \n%s\n};")%(self.name, fs)

    def parseBlob(self, blob):
        #TODO: call parseBlob recursively on each field in this struct
        pass

    def __str__(self):
        return "StructDef(%s){%s}"%(self.name, "\n\t".join([str(f) for f in self.fields]))


class RecordParser(object):
    """A RecordParser is defined in XML and can be used to convert
    physical records to logical records.  Additionally, it can output
    nesC-usable data structures.
    """

    def __init__(self, recordDef):
        tree = etree.parse(recordDef)
        root = tree.getroot()
        rtName = (root.xpath("/recordType/@name")[0])
        globalType = (root.xpath("/recordType/@globalType")[0])
        self.structs = {}
        for s in tree.xpath("/recordType/struct"):
            self.structs[s.xpath("@name")[0]] = StructDef(s)
        for s in self.structs:
            self.structs[s].linkDependencies(self.structs)
        #assumes that XML file is already in dependency order
        self.depOrder = tree.xpath("/recordType/struct/@name")


    def cStructStr(self):
        """Get the nesC nx_struct definition that this RecordParser
        handles.
        """
        return "\n".join([self.structs[s].cStructStr() for s in self.depOrder])

    def parsePhysicalRecord(self, pr):
        """Convert the binary data in a physical record to a
        logical record. 
        """
        #TODO: apply first format string to first chunk of data
        #      updates state
        #TODO: while more data remains, apply next format string and
        #      so on.
        pass

if __name__ == '__main__':
    rdf = open('descriptors/metadata.xml', 'r')
    rp = RecordParser(rdf)
