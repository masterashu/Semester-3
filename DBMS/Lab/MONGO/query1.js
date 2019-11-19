db.restaurants.find()
db.restaurants.find({}, { restaurant_id: 1, borough: 1, cuisine: 1 })
db.restaurants.find({}, { restaurant_id: 1, _id: 0, borough: 1, zipcode: 1 })
db.restaurants.find({}, { restaurant_id: 1, _id: 0, borough: 1, "address.zipcode": 1 })
db.restaurants.find({ borough: "Bronx" })
db.restaurants.find({ borough: "Bronx" }).limit(10).skip(5)
db.restaurants.find({ "grades.score": { $gt: 90 } })
db.restaurants.find({ $and: [{ "grades.score": { $gt: 80 } }, { "grades.score": { $lt: 100 } }] })
db.restaurants.find({ "address.coord.0": { $lt: -95.754168 } })
db.restaurants.find({ $and: [{ "address.coord.0": { $lt: 65.754168 } }, { "grades.score": { $gt: 70 } }, { "cuisine": { $ne: "American" } }] })
db.restaurants.find({ "address.coord.0": { $lt: -65.754168 } }).find({ "grades.score": { $gt: 70 } }).find({ "cuisine": { $ne: "American" } })
db.restaurants.find({ $and: [{ cuisine: { $ne: "American" } }, { "grades.grade": "A" }, { borough: { $ne: "Brooklyn" } }] }).sort({cuisine:-1})


        