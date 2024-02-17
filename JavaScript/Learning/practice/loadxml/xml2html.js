let books_table = document.getElementById("books")


let xmlContent = ''

fetch('xmldata.xml')
    .then((res) =>{
        res.text()
        .then((xml) => {
            xmlContent = xml
            let parser = new DOMParser();
            let xmlDom = parser.parseFromString(xmlContent, 'application/xml') // (data, type)
            let books = xmlDom.querySelectorAll("book");

            books.forEach(bookXmlNode => {
              let row = document.createElement("tr");

              //Author
              let td = document.createElement("td");
              td.innerText = bookXmlNode.children[0].innerHTML;
              row.appendChild(td);

              //Genre
              td = document.createElement("td");
              td.innerText = bookXmlNode.children[2].innerHTML;
              row.appendChild(td);

              //Title
              td = document.createElement("td");
              td.innerText = bookXmlNode.children[1].innerHTML;
              row.appendChild(td);

              //Published Date
              td = document.createElement("td");
              td.innerText = bookXmlNode.children[4].innerHTML;
              row.appendChild(td);

              //Price
              td = document.createElement("td");
              td.innerText = "$" + bookXmlNode.children[3].innerHTML;
              row.appendChild(td);

              //Description
              td = document.createElement("td");
              td.innerText = bookXmlNode.children[5].innerHTML;
              row.appendChild(td);

              books_table.children[1].appendChild(row);
            });
        })
    })
