# Bytes with &length

analyzer BytesLength withcontext {
	connection:	 BytesLengthConn;
	flow:		 BytesLengthFlow;
};

connection BytesLengthConn() {
	upflow = BytesLengthFlow(true);
	downflow = BytesLengthFlow(false);
};

type BytesLength = record {
    length: uint64;
    data: bytestring &length=length;
    rest: uint16;
} &byteorder = bigendian;

flow BytesLengthFlow(is_orig: bool) {
	datagram = BytesLength withcontext(connection, this);
};
