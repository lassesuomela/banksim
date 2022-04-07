<template>

</template>

<script>
export default{
    methods:{
        userLogout(){
            localStorage.removeItem("token");
            this.$router.replace("/login");
        }
    },
    beforeMount(){
        this.userLogout();
    }
}
</script>

