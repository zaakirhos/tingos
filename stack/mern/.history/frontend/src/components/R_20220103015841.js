import React, {useState, useEffect} from 'react'
import http from '../http-common.js'

const R = () => {
    const [r, setR] = useState([])

    const getRestaurants = () =>{
        http.get(``)
    }
    return (
        <div>
            
        </div>
    )
}

export default R
