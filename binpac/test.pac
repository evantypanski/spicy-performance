#analyzer Flow withcontext {
#	connection:	 Conn;
#	flow:		 Flow;
#};
#
#connection Conn() {
#	upflow = Flow(true);
#	downflow = Flow(false);
#};
#
#type BytesLength = record {
#    length: uint64;
#    data: uint8[] &until($element == 66);
#    rest: uint16;
#} &byteorder = bigendian;
#
#flow Flow(is_orig: bool) {
#	datagram = BytesLength withcontext(connection, this);
#};

analyzer WithRecord withcontext {
	connection:	 WithRecordConn;
	flow:		 Flow;
};

connection WithRecordConn() {
	upflow = Flow(true);
	downflow = Flow(false);
};

type WithRecordDat = record {
    length: uint64;
    data: Inner[] &length=length;
    rest: uint16;
} &byteorder = bigendian;

type Inner = record {
    b: uint8;
} &byteorder = bigendian;

flow Flow(is_orig: bool) {
	datagram = WithRecordDat withcontext(connection, this);
};
