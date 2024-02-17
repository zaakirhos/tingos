import React, {useState, useEffect} from 'react'
import http from '../http-common.js'

const R = () => {
    const [r, setR] = useState([])

    const getRestaurants = () =>{
        http.get(`?page=${0}`)
        .then((res) => {
            console,log(res.data)
            setR(res.data.restaurants);
        })
    }
    return (
        <div>
            
        </div>
    )
}

export default R
