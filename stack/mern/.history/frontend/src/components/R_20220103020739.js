import React, {useState, useEffect} from 'react'
import http from '../http-common.js'

const R = () => {
    const [r, setR] = useState([])

    const getRestaurants = () =>{
        http.get(`?page=${0}`)
        .then((response) => {
            console.log(response.data)
            setR(response.data.restaurants);
        })
    }

    useEffect(() => {
        getRestaurants()
        return () => {
        }
    }, [])
    return (
        <div>
            <h1>{r.length}</h1>
        </div>
    )
}

export default R
