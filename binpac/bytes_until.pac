# Bytes with &until

analyzer BytesUntil withcontext {
	connection:	 BytesUntilConn;
	flow:		 BytesUntilFlow;
};

connection BytesUntilConn() {
	upflow = BytesUntilFlow(true);
	downflow = BytesUntilFlow(false);
};

type BytesUntil = record {
    length: uint64;
    data: uint8[] &until($element == 66);
    rest: uint16;
} &byteorder = bigendian;

flow BytesUntilFlow(is_orig: bool) {
	datagram = BytesUntil withcontext(connection, this);
};
