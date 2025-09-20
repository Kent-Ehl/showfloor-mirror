// thwomp.inc.c

void grindel_thwomp_act_idle_at_bottom(void) {
    if (o->oTimer == 0) {
        o->oAction = GRINDEL_THWOMP_ACT_RAISE;
    }
}

void grindel_thwomp_act_lower(void) {
    o->oVelY += -40.0f;
    o->oPosY += o->oVelY;
    if (o->oPosY < o->oHomeY) {
        o->oPosY = o->oHomeY;
        o->oVelY = 0.0f;
        o->oAction = GRINDEL_THWOMP_ACT_LAND;
    }
}

void grindel_thwomp_act_land(void) {
    if (o->oTimer == 0) {
        if (o->oDistanceToMario < 1500.0f) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
        }
    }
    if (o->oTimer >= 10) {
        o->oAction = GRINDEL_THWOMP_ACT_IDLE_AT_BOTTOM;
    }
}

void grindel_thwomp_act_idle_at_top(void) {
        o->oAction = GRINDEL_THWOMP_ACT_LOWER;
}

void grindel_thwomp_act_raise(void) {
    if (o->oTimer > o->oBhvParams2ndByte + 40) {
        o->oAction = GRINDEL_THWOMP_ACT_LOWER;
        o->oPosY += 40.0f;
    } else {
        o->oPosY += 40.0f;
    }
}

void (*sGrindelThwompActions[])(void) = {
    grindel_thwomp_act_raise, grindel_thwomp_act_idle_at_top,    grindel_thwomp_act_lower,
    grindel_thwomp_act_land,  grindel_thwomp_act_idle_at_bottom,
};

void bhv_grindel_thwomp_loop(void) {
    cur_obj_call_action_function(sGrindelThwompActions);
}
