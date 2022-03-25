import Vue from 'vue'
import VueRouter from 'vue-router'
import LoginComponent from "../views/Login.vue"
import SecureComponent from "../views/secure.vue"

Vue.use(VueRouter)

const routes = [
    {
        path: '/',
        redirect: {
            name: "login"
        }
    },
    {
        path: "/login",
        name: "login",
        component: LoginComponent
        
    },
    {
        path: "/secure",
        name: "secure",
        component: SecureComponent
    }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

router.beforeEach((to, from, next) => {
  document.title = `${to.name}`;
  next();
});

export default router
