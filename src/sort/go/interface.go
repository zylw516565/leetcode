package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
)

// type ByteCounter int

// func (c *ByteCounter) Write(p []byte) (int, error) {
// 	*c += ByteCounter(len(p)) // convert int to ByteCounter
// 	return len(p), nil
// }

func main() {
	var w io.Writer
	w = os.Stdout
	f := w.(*os.File)
	fmt.Printf("%T, %v\n", f, f)
	f, ok := w.(*os.File)
	fmt.Printf("%T, %v, %v\n", f, f, ok)
	// c := w.(*bytes.Buffer)
	// fmt.Printf("%T, %v\n", c, c)
	c, ok := w.(*bytes.Buffer)
	fmt.Printf("%T, %v, %v\n", c, c, ok)

	//*******************
	w.Write([]byte("hello world\n"))
	rw := w.(io.ReadWriter) // success: *os.File has both Read and Write
	rw.Write([]byte("hello world 2\n"))
	var buf []byte
	rw.Read(buf)
	fmt.Println(string(buf))

	// w = new(ByteCounter)
	// rw = w.(io.ReadWriter) // panic: *ByteCounter has no Read method

	//*******************
	w = nil
	// v1 := w.(io.Writer)
	// fmt.Printf("%T, %v\n", v1, v1)

	// _, err := os.Open("/no/such/file")
	// fmt.Println(err)
	// fmt.Printf("%#v\n", err)
	// fmt.Println(os.IsNotExist(err))

	//*******************
	rsp := new(bytes.Buffer)
	writeHeader(rsp, "text/plain")
}

func writeString(w io.Writer, s string) (n int, err error) {
	type WriteString interface {
		WriteString(s string) (n int, err error)
	}

	if sw, ok := w.(WriteString); ok {
		return sw.WriteString(s)
	}

	return w.Write([]byte(s))
}

func writeHeader(w io.Writer, contentType string) error {
	// if _, err := w.Write([]byte("Content-Type: ")); err != nil {
	// 	return err
	// }

	// if _, err := w.Write([]byte(contentType)); err != nil {
	// 	return err
	// }

	// if ws, ok := w.(WriteString); ok {
	// 	ws.WriteString(contentType)
	// }

	if _, err := writeString(w, "Content-Type: "); err != nil {
		return err
	}

	if _, err := writeString(w, contentType); err != nil {
		return err
	}

	return nil
}

func sqlQuote(x any) string {
	if x == nil {
		return "NULL"
	} else if _, ok := x.(int); ok {
		return fmt.Sprintf("%d", x)
	} else if _, ok := x.(uint); ok {
		return fmt.Sprintf("%d", x)
	} else if b, ok := x.(bool); ok {
		if b {
			return "TRUE"
		}
		return "FALSE"
	} else if s, ok := x.(string); ok {
		return fmt.Sprintf("%q", s)
	} else {
		panic("sqlQuote: unknown type")
	}
}

func sqlQuoteV2(x any) string {
	switch x.(type) {
	case nil:
	case int:
	case uint:
	case bool:
	case string:
	default:
		return ""
	}

	return ""
}
