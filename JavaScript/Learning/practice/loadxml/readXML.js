let container = document.getElementById("text")


fetch("sample.xml").then(res =>{
     res.text()
        .then((xml) => {
             let parser = new DOMParser();
             let xmlDom = parser.parseFromString(text, "application/xml"); 
             console.log(xmlDom)
    
        })
}
)