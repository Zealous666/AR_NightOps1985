class NO_SCR_Bivouac_A_Action : ScriptedUserAction
{
	
    override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
    {
        
     	//Finish initital task
		IEntity taskEntityB = GetGame().GetWorld().FindEntityByName("tsk_bonus_A");
        NO_SCR_EditorTask taskB = NO_SCR_EditorTask.Cast(taskEntityB);
		taskB.ChangeStateOfTask(TriggerType.Finish);
        
        //Spawnpoint Hint
        SCR_HintManagerComponent hintComponent = SCR_HintManagerComponent.GetInstance();
        hintComponent.ShowCustomHint("New spawnpoint at Bivouac available", "SPAWNPOINT UNLOCKED", 10);
		
		//Unlocks spawnpoint
		SCR_SpawnPoint.Cast(GetGame().GetWorld().FindEntityByName("spawnPoint_A_bonus")).SetFactionKey("US"); 
        
        //Spawn Bivouac
		NO_SCR_SpawnTrigger.Cast(GetGame().GetWorld().FindEntityByName("bonus_A_spawnTrg")).Spawn();
		
		//Removes activator
		SCR_EntityHelper.DeleteEntityAndChildren(pOwnerEntity);
		
	}

}