# With Record

analyzer WithRecord withcontext {
	connection:	 WithRecordConn;
	flow:		 WithRecordFlow;
};

connection WithRecordConn() {
	upflow = WithRecordFlow(true);
	downflow = WithRecordFlow(false);
};

type WithRecordDat = record {
    length: uint64;
    data: Inner[] &length=length;
    rest: uint16;
} &byteorder = bigendian;

type Inner = record {
    b: uint8;
} &byteorder = bigendian;

flow WithRecordFlow(is_orig: bool) {
	datagram = WithRecordDat withcontext(connection, this);
};
