import http from '../http-common'

class RestaurantDataService {
  getAll(page = 0) {
    return http.get(`?page=${page}`);
  }

  createReview(data){
      return htt
  }

}
export default new RestaurantDataService();