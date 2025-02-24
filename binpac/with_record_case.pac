# With Record and a Case

analyzer WithRecordCase withcontext {
	connection:	 WithRecordCaseConn;
	flow:		 WithRecordCaseFlow;
};

connection WithRecordCaseConn() {
	upflow = WithRecordCaseFlow(true);
	downflow = WithRecordCaseFlow(false);
};

type WithRecordCaseDat = record {
    length: uint64;
    data: Inner[] &length=length;
    rest: uint16;
} &byteorder = bigendian;

type Inner = record {
    thing: case true of {
        true -> b: uint8;
    };
} &byteorder = bigendian;

flow WithRecordCaseFlow(is_orig: bool) {
	datagram = WithRecordCaseDat withcontext(connection, this);
};
