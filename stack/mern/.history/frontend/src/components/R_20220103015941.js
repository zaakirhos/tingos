import React, {useState, useEffect} from 'react'
import http from '../http-common.js'

const R = () => {
    const [r, setR] = useState([])

    const getRestaurants = () =>{
        http.get(`?page=${0}`)
        .then((res) => {
            console,log(res)
        })
    }
    return (
        <div>
            
        </div>
    )
}

export default R
